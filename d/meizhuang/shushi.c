// shushi.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ͺ���̵����ң�������һ���󰸣����Ϸ���һ����Ͳ����
Ͳ�в��ż��ܴ�С��ͬ��ë�ʣ�ë�ʵ�����Ҳ������ͬ�����Ǻ�����
����������ף������룬����һ֧���Ϻ��Ѽ�����̡���ʣ�����ƽ��
��һ���ĳ����ô�С����ֽ��һ�����⣬һ����ī��һ�԰�����ֽ��
һ����ɽ�ʼܣ����Գ����˶��鷨�İ��á�ǽ�Ϲ�����������д��һ
�������������ã������� 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"zoulang1",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/tubi-weng.c" : 1,
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

