// liangong4.c

inherit ROOM;

void create()
{
	set("short", "ժ��ͤ");
	set("long", @LONG
������һ����µ�ͤ�ӣ����˼䣬����ͤ��ľ��£����������˵Ļ���,ʹ
�˸е��Ŀ�������ͤ���ϻ���������ʫ�䡰���ְ�������Ҷ��������̵�¶�ҡ���
���ǵ����ʫ�˶Ÿ����ڰ�ʷ֮ս�ۣ�һ�ٱ���������һ�����������գ�������
��Խ���ս��ţ������Ĵ��ɶ���佻�Ϫ�ϣ�������ɢ�Ļ�֮�����ʵ�ʫ�䡣
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huayuan2",
		"south" : __DIR__"huajing", 
			
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",0);
	setup();
	replace_program(ROOM);
}
