// Room: /d/village/alley1.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ����
����ͨ��С��������˾����ǲ������Ǳ���ȥ�ġ������߾ͻ�ص�����
��·�ˡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"sroad3",
            "northwest" : __DIR__"alley2",
	]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}

