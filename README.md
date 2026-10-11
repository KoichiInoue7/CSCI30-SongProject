# Audio Playlist (C++)

A C++ playlist manager for songs and podcasts, built for CSCI 30 to practice
object-oriented design, memory management (RAII) and exception handling.

## What it does

- Builds a playlist that can hold both **songs** and **podcasts**
- Lists the playlist and "plays" each item in order
- Swaps two items by position, with error checking on the positions
- Handles a failed resource load without crashing: the item is skipped, the error is
  reported, and the rest of the playlist still works

## Design

```
AudioStream  (abstract base class: title, artist, duration, pure virtual play())
├── Song      adds album name
└── Podcast   adds episode number and guest

AudioBuffer  owns the raw audio memory for one stream (RAII)
Playlist     stores up to 100 streams and plays, lists and swaps them
```

- **Inheritance and polymorphism:** `Playlist` stores everything as `AudioStream*` and
  calls `play()`. Each subclass prints its own details.
- **RAII:** `AudioBuffer` loads its memory in the constructor and frees it in the
  destructor, so cleanup happens automatically when a stream is destroyed.
- **Exceptions:**
  - Loading a resource can throw `runtime_error`. `addSong` / `addPodcast` catch it,
    report the failure and keep going.
  - `swapSongs` throws `logic_error` if the playlist has fewer than 2 items, and
    `range_error` if an index is out of bounds.

## Build and run

```bash
g++ -std=c++17 main.cpp AudioStream.cpp Song.cpp Podcast.cpp Playlist.cpp AudioBuffer.cpp -o playlist
./playlist
```

## Example output

Two items are set up to fail on purpose, to show the exception handling:

```
Adding Song: Hotel California...
  [Playlist]: Failed to add Hotel California -> FATAL ERROR: Memory allocation failed!
...
--- Listing Your Playlist ---
0:The stream "Starman" is 250 seconds, performed by David Bowie.
1:The stream "Bohemian Rhapsody" is 354 seconds, performed by Queen.
2:The stream "Blinding Lights" is 200 seconds, performed by The Weeknd.
3:The stream "Tech Overload" is 1200 seconds, performed by Arun Maini.
--- Playing Your Playlist ---
Now playing Song: Starman by David Bowie [Album: Ziggy Stardust]
	Playing - Starman
...
  [RAII Cleanup]: freeing audio buffer memory...
```

## Files

| file | what it is |
|---|---|
| `main.cpp` | builds a sample playlist, lists it and plays it |
| `AudioStream.h/.cpp` | abstract base class |
| `Song.h/.cpp`, `Podcast.h/.cpp` | the two kinds of stream |
| `AudioBuffer.h/.cpp` | RAII wrapper around the audio memory |
| `Playlist.h/.cpp` | the playlist container |
| `supportFunctions.h` | provided by the course: simulated load / play / free functions |

## What I learned

This project grew as the class went on. Each time we covered something new, I added it
here: inheritance, then destructors and RAII, then exceptions. The biggest lesson was
how exceptions and memory interact. If an error is thrown halfway through, resources
still need to be cleaned up, which is why the buffer memory lives in a class whose
destructor frees it.

## Next steps

- Replace the raw pointer array in `Playlist` with `std::vector<std::shared_ptr<AudioStream>>`
- Add search and filtering (by artist, by type, by length)
