// Room: /d/village/bighouse2.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�����ң������м���һ�Ŵ󴲣����ϵı����Ȼ�ǳ�еģ�
����������������Լ�������ʮ�ֿ̱���������ż�ֻľ���ӣ�ǽ������
һֻ�����(cabinet)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" :"/d/village/bighouse1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
