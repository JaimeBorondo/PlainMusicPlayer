#include "Playlist.h"
#include "SoundSystem.h"
#include <algorithm>

float Playlist::volume_ = 0.2f;

PlaylistInfo::PlaylistInfo(const std::vector<const SongInfo *> &songs) : songs_(songs)
{}

const std::vector<const SongInfo *> &PlaylistInfo::GetSongList() const
{return songs_;}

//Playlist definition starts here

Playlist::Playlist()
{
    current_song_ = nullptr;
    current_song_idx_ = 0;
}

Playlist::Playlist(const Playlist &pl)
{
    current_song_ = nullptr;
    current_song_idx_ = 0;
    songs_ = pl.songs_;
}

Playlist::Playlist(const PlaylistInfo &pi)
{
	current_song_ = nullptr;
	songs_ = pi.GetSongList();
	current_song_idx_ = 0;
}

Playlist::~Playlist()
{
	if (current_song_ != nullptr)
		delete current_song_;
}

void Playlist::SetCurrentSong(unsigned idx)
{
	if (idx >= songs_.size())
		throw "Index out of bounds";

	current_song_idx_ = idx;
	UpdateCurrentSong();
}

void Playlist::NextSong()
{
	current_song_idx_ = ((current_song_idx_ + 1) % songs_.size());
	UpdateCurrentSong();
}

void Playlist::PreviousSong()
{
	current_song_idx_ = (current_song_idx_ == 0) ? static_cast<unsigned>(songs_.size()) - 1 : current_song_idx_ - 1;
	UpdateCurrentSong();
}

void Playlist::Pause()
{
	if(current_song_ != nullptr)
        current_song_->Pause();
}

void Playlist::UpdateCurrentSong()
{
	if (current_song_ != nullptr)
	{
		current_song_->Stop();
		delete current_song_;
		current_song_ = nullptr;
	}

	current_song_ = new Song(*songs_[current_song_idx_]);
	current_song_->Play();
    current_song_->SetVolume(volume_);
}

void Playlist::Update()
{
	//If the current song is finished playing, go to the next one, and play it
	if (current_song_ != nullptr)
	{
		//If position is reported as 0 and it is not playing anymore, it's over
		if (current_song_->GetPosition() == 0 && !current_song_->isPlaying())
			NextSong();
	}
}

void Playlist::Shuffle()
{
	if (current_song_ == nullptr)
	{
		std::random_shuffle(songs_.begin(), songs_.end());
	}
	else //We want to shuffle 'around' the current song
	{
		//Extract the current song
		const SongInfo *s = songs_[current_song_idx_];
		songs_.erase(songs_.begin() + current_song_idx_);
		//Shuffle remaining elements
		std::random_shuffle(songs_.begin(), songs_.end());
		//Insert current song
		songs_.push_back(s);
		//Swap with its old index
		std::swap(songs_.begin() + current_song_idx_, songs_.end() - 1);
	}
}


const std::vector<const SongInfo *> &Playlist::GetSongs()
{
    return songs_;
}


Song *Playlist::GetCurrentSong()
{
    return current_song_;
}

void Playlist::SetVolume(float vol)
{
    volume_ = vol;
}
