// dongjie.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书��Ķ��֣������߾����书�����ˡ��书���Ǹ�С
���򣬲��㷱�������ϵ�����Ҳ��ϡ�١�������һ�ҿ�ջ����ջ��
�ڹ��Ű븱�������翴�졯�Ķ����������Ѿ���˺���ˡ�������һ
����լԺ���������ϲ���ͭ���������������ߣ������书�����
���ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"zhongxin",
                "north" : __DIR__"kedian1",
                "south" : __DIR__"fu-damen",
        ]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
