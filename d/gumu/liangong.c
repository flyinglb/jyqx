// liangong.c ������
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ʯ����״�������أ�ǰխ�����Ϊ���Σ����߰�Բ������
ȴ��������״��ԭ��������ǰ������ʦ�������ң�ǰխ���ƣ����ʹ
ȭ����Բ�н������Ƿ��ڡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"zhengting",
                "north" : __DIR__"xiuxishi",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));

        setup();
        replace_program(ROOM);
}
