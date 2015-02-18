from google.appengine.api import users
import main
import utils
import webapp2


class GradeRecorderPage(webapp2.RequestHandler):
  def get(self):
    user = users.get_current_user()
    course = utils.get_course_from_key(self.request.get("course"))
    if not course:
      course = utils.get_default_course_for_user(user)
    if not course:
      course = utils.get_any_course_for_user(user)
    if course:
      self.load_page_for_course(course, user)
    else:
      self.load_courseless_page(user)

  def load_page_for_course(self, course, user):
    assignments, assignments_map = utils.get_assignments(user)
    students, students_map, teams = utils.get_students(user)
    grade_entries = utils.get_grade_entries(user, assignments_map, students_map)

    # Optional adding some meta data about the assignments for the badge icon.
    assignment_badge_data = {}
    for assignment in assignments:
      assignment_badge_data[assignment.key] = [0, 0]  # Accumulator for [Total Count, Total Score]
    for grade_entry in grade_entries:
      try:
        grade_as_float = float(grade_entry.score)
        assignment_badge_data[grade_entry.assignment_key][0] += 1
        assignment_badge_data[grade_entry.assignment_key][1] += grade_as_float
      except ValueError:
        continue
    for assignment in assignments:
      metadata = assignment_badge_data[assignment.key]
      if metadata[0] > 0:
        metadata.append(metadata[1] / metadata[0])  # Average = Total Score / Total Count
      else:
        metadata.append("na")  # Average is NA
    template = main.jinja_env.get_template("templates/graderecorder.html")
    self.response.out.write(template.render({'assignments': assignments,
                                             'active_assignment': self.request.get('active_assignment'),
                                             'students': students,
                                             'teams': teams,
                                             'grade_entries': grade_entries,
                                             'assignment_badge_data': assignment_badge_data,
                                             'user_email': user.email(),
                                             'logout_url': users.create_logout_url("/")}))

  def load_courseless_page(self, user):
    # TODO: Implement as a courseless page instead.
    assignments, assignments_map = utils.get_assignments(user)
    students, students_map, teams = utils.get_students(user)
    grade_entries = utils.get_grade_entries(user, assignments_map, students_map)

    # Optional adding some meta data about the assignments for the badge icon.
    assignment_badge_data = {}
    for assignment in assignments:
      assignment_badge_data[assignment.key] = [0, 0]  # Accumulator for [Total Count, Total Score]
    for grade_entry in grade_entries:
      try:
        grade_as_float = float(grade_entry.score)
        assignment_badge_data[grade_entry.assignment_key][0] += 1
        assignment_badge_data[grade_entry.assignment_key][1] += grade_as_float
      except ValueError:
        continue
    for assignment in assignments:
      metadata = assignment_badge_data[assignment.key]
      if metadata[0] > 0:
        metadata.append(metadata[1] / metadata[0])  # Average = Total Score / Total Count
      else:
        metadata.append("na")  # Average is NA
    template = main.jinja_env.get_template("templates/graderecorder.html")
    self.response.out.write(template.render({'assignments': assignments,
                                             'active_assignment': self.request.get('active_assignment'),
                                             'students': students,
                                             'teams': teams,
                                             'grade_entries': grade_entries,
                                             'assignment_badge_data': assignment_badge_data,
                                             'user_email': user.email(),
                                             'logout_url': users.create_logout_url("/")}))
