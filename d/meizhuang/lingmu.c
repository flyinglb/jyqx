// lingmu.c
inherit ROOM;

void create()
{
        set("short", "�Ż���");
        set("long", @LONG
��һ�ߵ����ͻȻһƬ������ԭ�����ﾹȻ�ǹŴ��ϴ�������
Ĺ���м�ͣ����һ�߹�ľ����ľ���Ϸ�������һ�Ŷ쵰һ���С��ҹ
���飬�������յ��쳣��������ľ�����з���һ���飬�鿴�����ܳ�
�ɣ��ƺ���һλǰ���������µġ� 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"didao5",
            "out" : __DIR__"hupan",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            "/clone/book/qunxing-tu.c" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

