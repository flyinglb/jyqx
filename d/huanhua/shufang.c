// shufang.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���������˵��鷿��һ�Ź��ⰻȻ���鰸���ڴ��£����ϰ��ż��������˵���
װ�鼮�������и���ܣ��Ա߻�����С�����������ˣ�������������һ�ᡣ������
��������(paper)��������д�������˿��ģ����ܵ�ǽ�Ϲ��ż����ֻ�����������
֮���������ǽ�Ͼ�Ȼ��֣���ŵġ�����ͼ���������Ե���ô���������¡�������
�������ϲ��ʤ��ϰ�䡣 
LONG
	);set("item_desc", ([ /* sizeof() == 1 */
  	"paper" : " 佻���®��С��(tree)д����2002/03/28�գ��Դ˴��."
]));
        set("exits", ([ 
		"south" : __DIR__"dating", 		
                "enter" : __DIR__"mishi",
]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
        setup();
        replace_program(ROOM);	
}
