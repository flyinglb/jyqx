// Room: /d/xingxiu/xxroad7.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������Сɽ���£����������һ�������������ǽ�ݶ�����ʽ������
�غ��˵�ש�ݣ�ֻ����Ϊ��ª��ֻ��С��֮��ϵ��һƥ��ͷ�������ȳ��ࡣ
�����ĵ�����С�����棬����̽ͷ�Ӵ�����������������֪������һ����ͬ
ʱ̽��������
LONG
        );
        set("exits", ([
            "southwest" : __DIR__"huijiang5",
        ]));
        set("objects", ([
                __DIR__"npc/ji"  : 1,
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
