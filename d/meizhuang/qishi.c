// qishi.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������Ƕ�ׯ���ڰ��ӵ������ˣ�����������ʯ�ʣ�һ��ʯ����
ʯ�����úڰ��ӵ�ָ�������ݺ�žŰ�ʮһ����������˼򵥵ķ���
�����������ɵ������⣬ʲô��û�У�������˫������ʱ���ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"zoulang2",
        ]));
        set("objects", ([ /* sizeof() == 1 */
             __DIR__"npc/heibai-zi.c" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
