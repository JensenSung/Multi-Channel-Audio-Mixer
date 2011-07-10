
#include <unistd.h>

#include "DebugMessage.h"
#include "PlaybackThread.h"

int main(void)
{
	PlaybackThread *playback = PlaybackThread::startPlaybackThread();

	if(playback)
	{
		size_t i = 0;

		while(i++ < 5)
		{
			TRACEF("Main thread sleeping...[%zu]\n", i);
			usleep(1000*1000*5);
		}

		TRACE("Shutting down playback thread...\n");
		delete playback;
		playback = NULL;
	}

	return 0;
}
