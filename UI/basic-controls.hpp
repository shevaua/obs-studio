#pragma once

#include <memory>

#include <QFrame>
#include <QPointer>
#include <QScopedPointer>
#include <obs.hpp>
#include <obs-frontend-api.h>

class OBSBasic;

#include "ui_OBSBasicControls.h"

class OBSBasicControls : public QFrame {
	Q_OBJECT

	std::unique_ptr<Ui::OBSBasicControls> ui;
	bool isStreamingActive = false;

	QScopedPointer<QMenu> streamButtonMenu;
	QPointer<QAction> startStreamAction;
	QPointer<QAction> stopStreamAction;

	static void OBSFrontendEvent(enum obs_frontend_event event, void *ptr);

private slots:
	void StreamingPreparing();
	void StreamingStarting(bool broadcastAutoStart);
	void StreamingStarted(bool withDelay);
	void StreamingStopping();
	void StreamingStopped(bool withDelay);

	void BroadcastStreamReady(bool ready);
	void BroadcastStreamActive();
	void BroadcastStreamStarted(bool autoStop);

	void RecordingStarted(bool pausable);
	void RecordingPaused();
	void RecordingUnpaused();
	void RecordingStopping();
	void RecordingStopped();

	void ReplayBufferStarted();
	void ReplayBufferStopping();
	void ReplayBufferStopped();

	void VirtualCamStarted();
	void VirtualCamStopped();

	void UpdateStudioModeState(bool enabled);

	void EnableBroadcastFlow(bool enabled);
	void EnableReplayBufferButtons(bool enabled);
	void EnableVirtualCamButtons();

public:
	OBSBasicControls(OBSBasic *main);
	inline ~OBSBasicControls() {}

signals:
	void StreamButtonClicked();
	void BroadcastButtonClicked();
	void RecordButtonClicked();
	void PauseRecordButtonClicked();
	void ReplayBufferButtonClicked();
	void SaveReplayBufferButtonClicked();
	void VirtualCamButtonClicked();
	void VirtualCamConfigButtonClicked();
	void StudioModeButtonClicked();
	void SettingsButtonClicked();
	void ExitButtonClicked();

	void StartStreamMenuActionClicked();
	void StopStreamMenuActionClicked();
	void ForceStopStreamMenuActionClicked();
};
