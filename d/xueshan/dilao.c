//      dilao.c ����
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����һ����������ʪ���η�����е���ֵ�������᲻
ʱ����һ�����ȴ��ôҲ�Ҳ�������? 
LONG );
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

