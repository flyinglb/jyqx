// shaluo.c

inherit ROOM;

void create()
{
        set("short", "ɯ��ƺ");
	set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ������
��ɽ·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "northwest" : __DIR__"path1",
            "northeast" : __DIR__"shanhongpb",
            "southup" : __DIR__"yunmen",
        ]));
        set("objects", ([
            __DIR__"npc/haoke": 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/shaluo", 1);
        return;
}
