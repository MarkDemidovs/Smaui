# SmaUI
A Work In Progress Framework (or as commonly known for now: Toolkit [1]) for creating CrossPlatform desktop software using "Widgets".

# Build Information
As per testing on Linux, It uses a custom Makefile, ran by using "make" in the root of the project.
By building the source files, it gets outputted in the "builds" folder, where youll find your ./app outputted file. (TBU - To Be Updated)
For the build to work, it must see the main.cpp file and any other files marked with the c++ extension under the "tools" folder, which holds all source code (Not written by the user).
SDL2 MUST be installed on your system, and as of now, the framework [1] has only been tested on Linux (specifically Arch way-land based systems.)

# Coding Information
For any user coding their own software using the framework [1], the code written must go into "main.cpp". It follows a simple while loop which acts as the main update loop. Check the file itself for more information.

# Formatting Information
All folders MUST be lowercase, and all source-code files (not written by the user) MUST be written starting with an upper case character.

# "Creative" Information
All fonts, default pictures and everything regarding looks are stored under tool -> creative, like Arial.ttf, the default font.

# Roadmap
This is basically a roadmap of features To Be Implemented.

0. ~~Basic Windows~~ (Version 0.1)

1. ~~Label (static text display)~~ (Version 0.2 + Version 0.2.1 - Colors)

2. ~~Button (clickable, with hover and pressed states)~~ (Version 0.3 + Version 0.3.1 - changeText())

3. ~~Panel (basic container to group widgets, with background color and positioning with widgets)~~ (Version 0.4)

4. ~~Text Input / Textbox (single-line user text entry)~~ (Version 0.5)

- Setting repository to be public <- We're here! ->

5. Checkbox (toggleable on/off box)

6. Radio Button Group (select one option from many)

7. Slider (drag to select value on a range)

8. Scrollbar (vertical or horizontal scroll control)

9. Tooltip (hover text info popup)

10. Image / Icon Widget (display images or icons)

11. Dropdown / Combo Box (select from a dropdown list)

12. Multiline Textbox / Text Area (larger, scrollable text input)

13. List View / Listbox (scrollable list of items, selectable)

14. Tab Control (tabs to switch between panels)

15. Progress Bar (visual progress indicator)

16. Menu Bar (top window menu with dropdown items)

17. Popup / Modal Dialog (floating window for alerts, confirmation)

18. Tree View (expandable hierarchical list)

19. Grid / Table View (multi-column data display)

20. Canvas / Drawing Area (custom paint/draw widget)

21. Split Pane / Resizable Panes (adjustable sub-window areas)

22. Drag and Drop Support (drag widgets or data between areas)

23. Animations and Transitions (smooth UI effects on widgets)

24. Focus Management and Keyboard Navigation (tab key, arrows)

25. Accessibility Support (screen readers, high contrast modes)

26. High DPI / Retina Display Support (sharp, scaled UI)

27. Window Features: Resizing, Minimizing, Maximizing, Fullscreen

28. Window Decorations (Custom Title Bar and Borders)

29. Multiple Window Support (popup windows, dialogs, multi-doc)

30. Window Transparency and Layering (Alpha blending)

31. Drag Window by Custom Title Bar (click-and-drag to move)

32. Window Snap and Docking Features

33. Window Theming / Skinning (dynamic style change at runtime)

34. Window State Persistence (save/restore size, position)

35. Multi-Monitor Support and DPI Awareness