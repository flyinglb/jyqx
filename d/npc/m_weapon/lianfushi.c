//ROOM lianfushi.c
inherit ROOM;

void create()
{
        set("short", "�͸���");
        set("long",@LONG
�����������Ŷ�����ս���ĵط���λ������ɽ����һ����������
��������ɽ��֮�С�������ּ��ɽ���ϣ�һ�����Ǻܴ��¯Ҥ�ߣ�
һ��Ӣ�˲���������վ��������������˹�����
LONG	);
        set("exits", ([
                "east" : "/d/gaochang/room63",
        ]));

	set("objects",([__DIR__"npc/shifu" :1,]));

        setup();
	replace_program(ROOM);
}
