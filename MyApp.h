/* MyApp */

#import <Cocoa/Cocoa.h>

@class RepositoriesController, FavoriteWorkingCopies;

/* " Application's main controller." */
@interface MyApp : NSObject
{
    IBOutlet id							preferencesWindow;
	IBOutlet id							favoriteWorkingCopiesWindow;	// Unused
	IBOutlet id							tasksManager;
	IBOutlet RepositoriesController*	repositoriesController;
	IBOutlet FavoriteWorkingCopies*		favoriteWorkingCopies;
	UInt32								fSvnVersion;
}


+ (MyApp*) myApp;

// AppleScript Handlers
- (void) displayHistory:  (NSString*) path;	// Compare a single file in a svnX window.
- (void) openWorkingCopy: (NSString*) path;	// Open a working copy window.
- (void) openRepository:  (NSString*) url;	// Open a repository window.
- (void) openFiles:       (id) fileOrFiles;	// Open files in appropriate applications.
- (void) diffFiles:       (id) fileOrFiles;	// Compare files against BASE.

- (IBAction)  openPreferences:  (id) sender;
- (IBAction)  closePreferences: (id) sender;
- (BOOL)      svnHasLibs;
- (void)      setSvnHasLibs:    (id) ignore;
- (UInt32)    svnVersionNum;
- (NSString*) svnVersion;
- (void)      setSvnVersion:    (NSData*) version;

- (void)      openRepository:   (NSURL*)    url
			  user:             (NSString*) user
			  pass:             (NSString*) pass;

- (void)      newTaskWithDictionary: (NSMutableDictionary*) taskObj;
- (NSString*) getMACAddress;

@end

