inherit ROOM;

void create()
{
        set("short", "Ĳ����");
        set("long",@LONG
���Ǹ�ɮ�ǵľ���֮��������ȫ����ľ�Ƴɣ�����ľ����ľ�Ͼ���ȥ
Ƥ����Ȼ���ӣ���һ·������̻Ի͵ĵ��ý�Ȼ��ͬ������������з���
������š���ɮ���⣬����һ�������泯���һ��������
LONG
        );
        set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
                __DIR__"npc/benchen" : 1,
		__DIR__"npc/kurong" : 1,
		__DIR__"npc/benguan" : 1,
		__DIR__"npc/benxiang" : 1,
		__DIR__"npc/bencan" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
