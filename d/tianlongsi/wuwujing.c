inherit ROOM;

void create()
{
        set("short", "���޾�");
        set("long",@LONG
һƬˮ�ؾ�����ǰ��һ������ľ�ź�����ϣ����䵹Ӱǡ��һԲ��ӳ
�ſ����ˮ�棬ʹ�����������������·���ᵽ������֮Դ������֮����
���С�
LONG );
        set("outdoors","tianlongsi");
        set("exits", ([
            "north": __DIR__"yaotai",
            "south": __DIR__"qingxinge",    			
            "west" : __DIR__"cibeiyuan",
            "east" : __DIR__"yuhuayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
