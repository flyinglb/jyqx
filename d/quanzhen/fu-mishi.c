// fu-mishi.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�����ң�����ɢ���ż�����Ѫ�ı��ӣ�����һЩ��
�ָ������̾ߡ�������˵��Ȼ���飬���Ա������Ǹ���������
�Ķ�ԡ�
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"fu-midao",
                "up" : __DIR__"fu-woshi",
        ]));
        set("objects", ([
                __DIR__"obj/xuejie" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
