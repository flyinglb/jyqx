// Room: /d/emei/wuchang.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����Ƕ����ɵ����䳡�����䳡�������������ɵ������ڴ�ϰ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wcaolian",
  "south" : __DIR__"scaolian",
  "north" : __DIR__"hcaguangchang",
 "east" : __DIR__"ecaolian",
]));
        set("no_clean_up", 0);
        set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
