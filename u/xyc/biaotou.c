//biaotou.c ����ͷ
inherit NPC;

#include <ansi.h>
 
int yunbiao();

void create()
{
        set_name("����ͷ", ({ "biaotou"}));
        set("gender", "����");
        set("age", 56);
        set("long", "�ھֵ�����ͷ,�ƺ����б���!��\n");
        
        set("combat_exp", 500000);
        set("shen_type", 1);

        set("chat_chance",2);
        set("chat_msg", ({
                "����ͷ˵��,�ھ�����Ҫ���֡�\n",
                  "����ͷ˵��,Ҫ����Щ�ܸɵ��˰�æ���ھͺ���......\n",
                  "����ͷ˵��,��ʦ̫���ˣ�������ֻ��һ��Ͳ����ˣ�....\n",
        }) );
        set("attitude", "peaceful");
        
        set("inquiry", ([
                  "����" : "�������һ�û�����أ�\n",
                  "����" : "�������һ�û�����أ�\n",
//                  "����" : (: yunbiao :),
//                  "����" : (: yunbiao :),
        ]) );
        
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 500);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",10);
}

