// Room: /d/city/chaguan3.c

inherit CHATTING_ROOM;

void create()
{
        set("short", HIM"����"NOR);
        set("long", @LONG
����ǲ����Ĳ��ҡ����ﲼ�õúܵ��ţ�����������Ƣ�����ܵ�
���һ��Ʒ�裬һ���ڹۿ�һ�̲о֡�����ʱ��������˽���������ʲ
ô���㲻�ɵô��˹�ȥ��������������
LONG
        );
//        set("resource/water", 1)
	set("exits", ([
                "south"  : __DIR__"chaguan",
	]));
        set("objects", ([
                __DIR__"obj/cch" : 1,
        ]));
        setup();
}
