// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("������", ({ "hua tiegan", "hua" }));
       set("long", 
       "�����������桰�仨��ˮ���е��϶���\n"
       "��������н��ϣ��������壬������һ����ƽǹ���ų���ƽ�޵С���������Ϊ��ȴ��զ�ġ�\n");
       set("gender", "����");
       set("nickname", HIR"��ƽ�޵�"NOR);
       set("age", 45);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("max_qi", 2000);
       set("max_jing", 500);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 30);
       set("combat_exp", 700000);
       set("shen_type", 0);

       set_skill("force", 100);
       set_skill("huashan-neigong", 100);
       set_skill("dodge", 100);
       set_skill("lingxu-bu", 100);
       set_skill("unarmed", 100);
       set_skill("huashan-ken", 100);
       set_skill("parry", 100);
       set_skill("club", 100);
       set_skill("zhongping-qiang", 100);
       set_skill("literate", 40);

       map_skill("force", "huashan-neigong");
       map_skill("dodge", "lingxu-bu");
       map_skill("unarmed", "huashan-ken");
       map_skill("club", "zhongping-qiang");
       map_skill("parry", "zhongping-qiang");
       set("chat_chance", 20);
       set("chat_msg", ({
              "�����ɻ�������������Х���糱ӿ�������仨������ˮ���������˶�����\n",
       }));

       setup();
       carry_object("/clone/weapon/changqiang")->wield();
}

