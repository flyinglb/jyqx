// houhuayuan.c ��԰
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
������һ��С��԰�����ҵ����Ÿ��ֻ��ݣ��������˴���
�Ӳ��Ѿ����úܸ��ˡ���һЩ��ģ��׵��ʻ������ڲݴ��У���
���㲻�ϵ�Ʈ����������һ��С�ţ�������һ������С¥��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"fu-houyuan",
                "south" : __DIR__"guanjinglou",
                "east" : __DIR__"houhuayuan1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
