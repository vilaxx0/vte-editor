#ifndef EDITOR_H
#define EDITOR_H

#define ABUF_INIT {NULL, 0}
#define VTE_VERSION "0.0.1"
#define KILO_TAB_STOP 8

enum EDITOR_KEY {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DELETE_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};

struct ABuf {
  char *b;
  int len;
};

void editorInit();
void editorOpen(char* filename);
void editorMoveCursor(int key);
int editorReadKey();
void editorProcessKeypress();
void editorRefreshScreen();
void editorDrawRows(struct ABuf *aBuf);
void editorScroll();
int getWindowSize(int* rows, int* cols);
int getCursorPosition(int* rows, int* cols);
void aBufAppend(struct ABuf* aBuf, const char* s, int len);
void aBufFree(struct ABuf* aBuf);
void editorAppendRow(char *s, size_t length);
void editorUpdateRow(EditorRow *row);
int editorRowCxToRx(EditorRow *row, int cursorX);

#endif