#ifndef __SIM_HOME__
#define __SIM_HOME__

#include <QObject>
#include <QString>
#include <QPixmap>
#include <planning/STRIPS_Problem.hxx>

namespace Planning
{

class Observer;

}

namespace UI
{

class RoomView;

}

namespace Application
{

class 	Home;
class	Goal;

class SimHome : public QObject
{
	Q_OBJECT
public:

	SimHome();
	~SimHome();

	aig_tk::STRIPS_Problem&		planningDomain() { return mDomain; }
	Planning::Observer*		observer() { return mObserver; }
	
signals:
	
	void	onHomeLoaded( const QPixmap& pic );
	void	makeRoom( UI::RoomView*	v );
	void	updateInitialState( aig_tk::Fluent_Vec& eval );

public slots:

	void	quit();
	void	loadHome( const QString& homePath );
	void	initialStateUpdateRequested();

private:

	Home*				mHome;
	aig_tk::STRIPS_Problem		mDomain;
	Planning::Observer*		mObserver;
};

}

#endif // SimHome.hxx