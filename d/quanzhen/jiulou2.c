// jiulou2.c

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("short", "��¥��¥");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ�������
�Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������
ֻ�����Ļ�̹��������ȫ�������Ļ�ɳ����֮���ϵĻ���������Ƹ�
�ǺƵ�����¥��ǽ�Ϲ���һ������(paizi)��
LONG
        );
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));

        setup();
        replace_program(ROOM);
}
