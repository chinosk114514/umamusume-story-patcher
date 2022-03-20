# umamusume-story-patcher

*Now works with the latest version of UnityPy*



## Modified

- Add `hash calc` for **[umamusume-localify](https://github.com/chinosk114514/umamusume-localify)**

- Add `json` output
- **`cppy_gb.pyd` in the folder only works in `windows - Python 3.8`. **
  - If you want to work in other python version, see **[pybind11](https://github.com/pybind/pybind11)** and compile `hash_calc` yourself or download `.exe` from [Release](https://github.com/chinosk114514/umamusume-story-patcher/releases).



## How to use

* Go to your umamusume folder, usually  
`C:\Users\<user>\AppData\LocalLow\Cygames\umamusume`
* Make a mods folder and clone this repo inside it  
`C:\Users\<user>\AppData\LocalLow\Cygames\umamusume\mods\umamusume-story-patcher`
* Run `python pip install -r requirements.txt` in your terminal
* Run `story_patcher.pyw`
* Extract some story
* Edit the csv file and change `Language` from `日本語` to `English`
* Put the file in the translations folder
* Patch All

## Infos

* You can take a look at the translated csv files (and the patched result in game)  
to see how the translations works  
* Hardcoded to translate only if the language is set to English for now but i'll  
add a settings tab some day  
* For any questions or suggestions DM me on discord (SkySet#3043)
