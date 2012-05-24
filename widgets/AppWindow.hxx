#ifndef UI_APPWINDOW_HXX
#define UI_APPWINDOW_HXX

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include <QPixmap>
#include <QGroupBox>

namespace UI
{

class  RoomView;
class  HomeRenderer;
class  GoalSetView;

class	AppWindow : public QMainWindow
{
	Q_OBJECT
public:
	AppWindow( QWidget* parent = 0, Qt::WindowFlags flags = 0 );
	virtual ~AppWindow();	

	QAction*	quitAction() 		{ return mQuitAction; }
	HomeRenderer*	homeScene()  		{ return mHomeScene; }
	QAction*	startObsAction() 	{ return mStartObsAction; }
	QAction*	stopObsAction()		{ return mStopObsAction; }
	GoalSetView*	goalSetView()		{ return mGoalsView; }

signals:
	void		loadHome( const QString& homeXmlPath );
	void		setObsLevel( float v );

public slots:
	
	void	onLoadHome();
	void	onHomeLoaded( const QPixmap& pic );
	void	makeRoom( UI::RoomView* view );
	void	setObsLevel10();
	void	setObsLevel30();
	void	setObsLevel50();
	void	setObsLevel70();
	void	setObsLevel100();

protected:

	void	setupWidgets();
	void	makeWidgets();
	void	makeFileMenu();
	void	makePRMenu();
	void	makeAboutMenu();

protected:
	// Widgets
	QAction* 	mLoadHomeAction;
	QAction* 	mQuitAction;
	QWidget* 	mCentralWidget;
	QWidget* 	mHorizontalLayoutWidget;
	QHBoxLayout* 	mHorizontalLayout;
	QGraphicsView*	mGraphicDisplay;
	QMenuBar* 	mAppMenuBar;
	QMenu*		mFileMenu;
	QMenu*	 	mAboutMenu;
	QStatusBar*	mStatusBar;
	HomeRenderer*   mHomeScene;
	QGroupBox*	mFloorPlanWidget;
	QVBoxLayout*	mFloorPlanWidgetLayout;
	GoalSetView*	mGoalsView;
	QMenu*		mPRMenu;
	QAction*	mStartObsAction;
	QAction*	mStopObsAction;
	QMenu*		mObsLevelMenu;
};

}

#endif // UI_APPWINDOW_HXX