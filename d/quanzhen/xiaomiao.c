// xiaomiao.c ������
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ԭ�����书���е�������������Ϊ�ܾ�û�����ɹ���
�Ѿ����ò���������ү�Ľ���Ҳֻʣ���˰�أ�����ֻʣ��������
�ȣ������Ѿ�ȫ���¹��ˣ���������ƶ������ûؼ�ȥ����ȡů��
����ƽ����û�������ģ�ֻ��һЩ���ֺ��еĵ�Ʀ��å֮�������
�����˼ҡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"xijie",
        ]));

        set("objects", ([
                __DIR__"npc/dipi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
