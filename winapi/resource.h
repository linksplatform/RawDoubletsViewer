//
// ЗАГОЛОВОК: RESOUCRE.H
//
// ОПИСАНИЕ: содержит определения идентификаторов ресурсов и элементов окна
//

// Для "статических" ресусов, события от которых можно не отслеживать
#ifndef resouce_h_
#define resouce_h_

#ifndef IDC_STATIC
#define IDC_STATIC                      -1
#endif

#define IDC_LISTVIEW                    1
#define IDC_STATUSBAR                   2

#define IDS_WNDCLASS                    10
#define IDS_ABOUTTITLE                  11
#define IDS_ABOUT                       12
#define IDS_ERROR                       13

#define IDDS_OPENTITLE                  20

#define IDS_COL                         50
#define IDS_COL_num                     9
#define IDS_COL_No                      50
#define IDS_COL_Source                  51
#define IDS_COL_Target                  52
#define IDS_COL_LasSrc                  53
#define IDS_COL_LasTrg                  54
#define IDS_COL_RasSrc                  55
#define IDS_COL_RasTrg                  56
#define IDS_COL_SrcSize                 57
#define IDS_COL_TrgSize                 58

// Главное меню
#define IDM_MAINMENU                    100
#define IDM_OPEN                        101
#define IDM_ABOUT                       102

#endif
