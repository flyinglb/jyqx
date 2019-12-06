// hlj_npc.c ��������

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("С����", ({"xiao san", "xiao", "san"}));
        set("gender", "����");
        set("nickname",HIR"��������"NOR);
        set("age", 26);
        set("long", 
                "���Ǻ����̵�һ�����ڣ����ƺ������š�\n");
        set("attitude", "peaceful");
        
        set("str", 25);
        set("int", 17);
        set("con", 18);
        set("dex", 27);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        
        set("combat_exp", 15000);
         
        set_skill("force", 20);             
        set_skill("unarmed", 30);           
        set_skill("dodge", 20);             
        set_skill("parry", 30);             
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
}
