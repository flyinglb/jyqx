// sroad6.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽ��");
        set("long",@LONG
����ѩ�أ�����̹ǡ���������������ˣ���Ȼ���ܲ�ס�ˡ�
LONG );
        set("exits",([
                "northdown" : __DIR__"sroad5",
                "westup"    : __DIR__"sroad7",
        ]));
        set("outdoors", "xueshan");
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
