// Room: /u/mei/room33.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��");
    set("long", @LONG
�߹��˳���һ�������������ӳ���˵�Ӱ�ӣ���ʱ����帹�����׻�����
�������ϣ���ƽ����֮�棬ʵ�Դ�ʱΪ���ˡ�
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room34",
]));
    setup();
    replace_program(ROOM);
}
