//westroad2.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @TEXT
�Ѿ����˺ܾã�ɽ��Խ��Խ�ܣ�ҹ�������ˣ�ҹ�ɺ��ţ�
����ë���Ȼ�����ǡ�����ѣ����������족������������Ҫ
��ɽ�ˡ�ͻȻ�����ַ������������ǻ�⡣
TEXT );
	set("exits",([
	    "east" : __DIR__"westroad1",
	    "west" : __DIR__"gebitan1",
            "south" : __DIR__"miaorenbuluo",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
