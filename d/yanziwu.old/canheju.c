//ROOM: /d/yanziwu/canheju.c

inherit ROOM;

void create()
{
        set("short", "�κϾ�");
        set("long",@LONG
����Ľ���������������ճ����֮�أ����õû����в������ţ�ƽ
ʵ��͸�Ÿ߹��ľ��������̫ʦ�Σ��Լ�ǽ�ϵ��ֻ���͸��һ�ɷǷ�
֮����
LONG  );
        set("exits", ([
            "west" : __DIR__"qiushuan",
            "east" : __DIR__"zuijing",
            "north": __DIR__"yimen",
            "south": __DIR__"shuwu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
