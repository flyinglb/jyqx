//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC; 

void create()
{
        set_name("������",({"wang wanyi","wang"}));
        set("nickname", HIG"���Ϸ�"NOR);
        set("gender", "����");
        set("age", 20);
        set("long", 
               "���������ǵ��������ӹ�����,�������������Ṧ������\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 40);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jing", 1000);
        set("max_jing", 1000);
        set("max_qi", 2000);
        set("qi", 2000);
        set("jiali", 50);
        set("inquiry", ([
            "dodge"   : "�ҵ��Ṧ�𡭡�?����������,�������Ṧ�ĺõط���\n��ү�ӻ���֪�������ı���������һ���ö�����",
            "�Ṧ"   : "�ҵ��Ṧ�𡭡�?����������,�������Ṧ�ĺõط���\n��ү�ӻ���֪�������ı���������һ���ö�����",
        ]) ); 


        set("combat_exp", 200000);
        set("shen_type", 1);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 200);
        set_skill("literate", 80);

        set_skill("xueshan-sword", 100);
        set_skill("bingxue-xinfa", 100);
        set_skill("snow-zhang", 100);
        set_skill("snowstep", 200);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
} 


