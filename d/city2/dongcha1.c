
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ƕ������֣������Ľֵ��ϳ�ˮ���������������������߾�
���찲���ˡ�������������־��ڱ��ߣ�����˶�����ȥ����������
���У��ƺ�ʮ�����֡����֮�£����߾��Ե�������ˡ�
LONG );
        set("no_sleep_room",1);
        set("outdoors", "city2");
	set("objects", ([
		"/d/mingjiao/npc/baiguishou" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"dongcha2",
		"west" : __DIR__"tian_anm",
		"north" : __DIR__"wangfu1",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

