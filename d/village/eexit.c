// Room: /d/village/nwexit.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǻ�ɽ���£���ȻԶ���سǣ�ȴû��ʲ��ɽ���ݿ��ڸ�����û��
����������ɽ��·�ˡ�������һ��С��ׯ���������˼Ҳ����࣬�����ǹ�
���ճ������������Ϣ���������
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"eroad1",
		"east" : "/d/huashan/path1",
	]));
        set("objects", ([
            __DIR__"npc/boy": 1
        ]) );

//        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
        replace_program(ROOM);
}

