#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW "�࿼��ʦ" NOR,({"jiankao teacher"}));
        set("nickname", BLINK+HIC"�ɶ��"NOR);
        set("gender", "����");
        set("age", 30);
        set("long", 
                "����һ��ר��ץ�����׵ļ࿼��ʦ��\n");

        setup();
        
        carry_object("/d/city2/obj/jinduan")->wear();
}

