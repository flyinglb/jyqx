//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "ʯ�¿�ջ");
	set("long", @LONG
������ѩɽɽ·�ϵ�һ���ջ����Ȼ�������ʵ��ƽ��Ҳ
��������ʲô�ο�����ѩ����ɽ��ˮ���������ѩɽ�ϣ�ȴҲ��
��һ�޶��Ŀ�ջ��������ط���Ҫ�ǲ��붳��������������ϣ�
ֻ�»��ǵ��չ�һ����������⡣������ҵ굹Ҳ��������¡��
LONG );
	set("exits", ([
                "west" : __DIR__"shiya",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
                __DIR__"npc/dizi" : 2,
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

