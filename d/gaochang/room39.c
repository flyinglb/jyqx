// Room: /u/mei/room39.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "��");
    set("long", @LONG
����һ���ݼ��������ݼ�����ʮ����·��ǰ���Ȼ���ʣ�����һ��Ƭƽ�ء�
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ 
  "down" : __DIR__"room40",
]));
    setup();
    replace_program(ROOM);
}
