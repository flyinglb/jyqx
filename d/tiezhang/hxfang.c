// Room: /u/zqb/tiezhang/hxfang.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
    ���Ǵ��������һ��С���䣬��ȻҲ����ʯ���ɣ������õķǳ�
���ʡ��ı��ù�̺��ס����¶һ��ʯ�ڵĺۼ�������תȦ�ڷ���һЩ���ӣ�
�������ź�����棬����ȥһ�������ʡ������ǰ�����������ճ������ 
�ط�������ͨ���Ժ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"hhyuan-1",
            "south" : __DIR__"wztang",
        ]));
	 set("objects", ([
            __DIR__"npc/yahuan" : 1,
        ]));

        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

