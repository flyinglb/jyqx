// room: dong-2.c
// zqb


inherit ROOM;
#include <ansi.h>
string look_bei();
void create()
{
        set("short", HIR"��Ȼ��Ѩ"NOR);
        set("long", @LONG
    ��ʯ��ϵ��Ȼ���ɣ���֮�����˹������ʯ�Ҵ���ʮ������������
ȥ�����ڹ���ʮ��ߺ��ǣ��������ԣ���̬���в�ͬ���еĺ���ɢ���ڵأ�
�е�ȴ�Ծ�������Σ�����Щ��̳��λ֮����ÿ�ߺ���֮�Զ����ű��У���
�����þߣ��䱦������ڴ�����һ��ʯ��(bei)��
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-3",
        ]));
        set("item_desc",([
        "bei"         :       (: look_bei :),
    ]));

        set("objects", ([
           
        __DIR__"obj/haigu2" : 1,  
        __DIR__"obj/ycj" : 1,      
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}
string look_bei()
{
        return
        "\n"
"    �   �ö�������Ʒ��\n"    
        "\n"
RED"        ����Ī�֣�    \n"NOR
        "\n";
}

