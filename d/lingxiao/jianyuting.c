//LUCAS 2000-6-18
// jianyuting.c

inherit ROOM;

void create()
{
        set("short", "����С��");
        set("long", @LONG
������������ǵļ�����ڡ������ǵļ���ר��������Ѻ��
���Ź�ĵ��ӣ�һЩ���е����鷸�ƣ���������֮ͽҲ˳����Ѻ
�ڴˡ���������һ�����ɣ������Ź�ɭ�ϣ���Ҳ���з����ߣ���
�����������صأ�������Ҳ���ܡ�
LONG );
        set("outdoors", "lingxiao");
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("no_clean_up", 0);

        set("exits", ([
                "west" : __DIR__"iceroad3",
                "down" : __DIR__"laolang",
        ]));
        set("objects", ([ 
                __DIR__"npc/yan" : 1,
                __DIR__"npc/dizi" : 3,
        ])); 
        setup(); 
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir=="down" 
            && objectp(present("yan wanpeng", environment(me)))
            && (me->query("family/master_id")!="bai zizai"))
                return notify_fail(
"���������һ�����˴��˱��ɽ��أ���λ" + RANK_D->query_respect(me) + 
"��ֹ����\n");
        return ::valid_leave(me, dir);
}

