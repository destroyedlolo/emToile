# emToile
Lvgl based framework to build GUI on **Arduino IDE** compatible embedded systems

**This LEGACY branch is now obsolete** : the main branch contains redesigned version which is more more economical and efficiant compared to this one.
Legacy branch is still here for maintenance reason but will not be updated as soon as the main one is stable enough.

## installation

Clone this repository in your **Arduino IDE libraries** directory (i.e. ``~/Arduino/libraries``)

[lvgl](https://lvgl.io/) is expected to be installed and accessible thru "lvgl/" include sub directory (it's the case if you're using [Xinyuan-LilyGO /TTGO_TWatch_Library](https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library)

## Documentation (lack of)

Each header file is an implementation of an Lvgl object and contains related usage documentation.

---

[Toile](https://github.com/destroyedlolo/Toile) is a framework to build GUIs on Unix system using **Lua**. **emToile** has the same goal for embedded systems but not using Lua. It's why I choose the change sightly the name and create a dedicated directory.
