// yzuo.c ����
 
#include <ansi.h>
 
inherit NPC;
 
void create()
{
        set_name("����", ({"yzuo"}));
        set("nickname",HIM"������ʦ"NOR);
        set("gender", "����");
        set("age", 20);
        set("long",
                "�����Ǹ��������������ɴ�ҵ�Ĵ���ʦ���꣡\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

