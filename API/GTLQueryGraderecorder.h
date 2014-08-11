/* This file was generated by the ServiceGenerator.
 * The ServiceGenerator is Copyright (c) 2014 Google Inc.
 */

//
//  GTLQueryGraderecorder.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   graderecorder/v1
// Description:
//   Grade Recorder API
// Classes:
//   GTLQueryGraderecorder (7 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLGraderecorderAssignment;
@class GTLGraderecorderGradeEntry;

@interface GTLQueryGraderecorder : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (copy) NSString *assignmentKey;
@property (copy) NSString *entityKey;
@property (assign) long long limit;
@property (copy) NSString *order;
@property (copy) NSString *pageToken;

#pragma mark -
#pragma mark "assignment" methods
// These create a GTLQueryGraderecorder object.

// Method: graderecorder.assignment.delete
// Delete the assignment with the given key, plus all the associated grade
// entries
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderAssignment.
+ (id)queryForAssignmentDeleteWithEntityKey:(NSString *)entityKey;

// Method: graderecorder.assignment.insert
// Add or update an assignment owned by the given user
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderAssignment.
+ (id)queryForAssignmentInsertWithObject:(GTLGraderecorderAssignment *)object;

// Method: graderecorder.assignment.list
// List all the assignments owned by the user
//  Optional:
//   limit: long long
//   pageToken: NSString
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderAssignmentCollection.
+ (id)queryForAssignmentList;

#pragma mark -
#pragma mark "gradeentry" methods
// These create a GTLQueryGraderecorder object.

// Method: graderecorder.gradeentry.delete
// Delete the grade entry with the given key
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderGradeEntry.
+ (id)queryForGradeentryDeleteWithEntityKey:(NSString *)entityKey;

// Method: graderecorder.gradeentry.insert
// Add or update a grade entry for an assignment
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderGradeEntry.
+ (id)queryForGradeentryInsertWithObject:(GTLGraderecorderGradeEntry *)object;

// Method: graderecorder.gradeentry.list
// List all the grade entries for the given assignment key
//  Optional:
//   limit: long long
//   order: NSString
//   pageToken: NSString
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderGradeEntryCollection.
+ (id)queryForGradeentryListWithAssignmentKey:(NSString *)assignmentKey;

#pragma mark -
#pragma mark "student" methods
// These create a GTLQueryGraderecorder object.

// Method: graderecorder.student.list
// List all the students for this user
//  Optional:
//   limit: long long
//   order: NSString
//   pageToken: NSString
//  Authorization scope(s):
//   kGTLAuthScopeGraderecorderUserinfoEmail
// Fetches a GTLGraderecorderStudentCollection.
+ (id)queryForStudentList;

@end
