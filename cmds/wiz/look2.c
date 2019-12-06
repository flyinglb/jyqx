// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// look.c
// "per" parts modified by none at 96/10/02

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

string *per_msg_male1 = ({
        CYN "����ΰ��Ӣͦ������֮�䣬��ɷ��\n" NOR,
        CYN "����Ӣΰ������������ȷʵ���������\n" NOR,
});

string *per_msg_male2 = ({
        CYN "Ӣ��������������档\n" NOR,
        CYN "��ò���ڣ���Ŀ���ʡ�\n" NOR,
        CYN "��ò���棬���˷��ס�\n" NOR,
});
string *per_msg_male3 = ({
        CYN "��òƽƽ��ûʲô�ÿ��ġ�\n" NOR,
        CYN "��ò�׶��������⡣\n" NOR,
        CYN "�������ۣ��������硣\n" NOR,
});
string *per_msg_male4 = ({
        CYN "����һ�����Ѳ��ۣ��˾˲�����ģ����\n" NOR,
        CYN "��������ģ�һ���޾���ɵ�ģ���� \n" NOR, 
        CYN "������֣���ͷ������������˽�ı��ҡ� \n" NOR, 
});
string *per_msg_female1 = ({
        CYN "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� \n" NOR,
        CYN "������������Ŀ���飬����һЦ������������Ȼ�Ķ��� \n" NOR,
        CYN "�������֣��������ˣ��������Ҽ������� \n" NOR, 
});
string *per_msg_female2 = ({
        CYN "������������ɫ���������˶��ˡ� \n" NOR,
        CYN "���潿�ݻ���¶������ϸ�������̡� \n" NOR,
        CYN "����κ죬�ۺ��ﲨ������Ͷ��֮�䣬ȷ��һ�����ϡ� \n" NOR,
});
string *per_msg_female3 = ({
        CYN "���㲻�Ͼ������ˣ�Ҳ���м�����ɫ�� \n" NOR,
        CYN "���û��������м�����ɫ��  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "���ñȽ��ѿ��� \n" NOR,
        CYN "���á���������  \n" NOR,
});

string *per_msg_kid1 = ({
        CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
        CYN "������ã���̬�Ƿ���\n" NOR,
        CYN "�������£�ɫ��������\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "¡����ۣ���ɫ����\n" NOR,
        CYN "�����ལ�����ϲ����\n" NOR,
        CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "����󰫣�ɵ��ɵ����\n" NOR,
        CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
        CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
});

string *per_msg_kid4 = ({
        CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
        CYN "����ľ�������в�ɫ��\n" NOR,
        CYN "��ٲ�������֫���ࡣ\n" NOR,
});

// snowcat 12/20/97
string ride_suffix (object me)
{
  string ridemsg = "";
  object ridee = 0;

  if (ridee = me->query_temp("ridee")) { 
    if (environment(ridee) != environment(me) ||
        ! living(ridee) ||
        ! living(me)) {
     me->set_temp("ridee",0);
     ridee->set_temp("rider",0);
     ridee = 0;
    }
    else
      ridemsg = " <"+ridee->query("ride/msg")+"��"+ridee->name()+"��>";
  }
  if (! ridee) {
    me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
    me->set_temp("ride/dodge",0);
  }
  return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
   object obj;
   int result;

   if( !arg ) result = look_room(me, environment(me));
   else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
     if( obj->is_character() ) result = look_living(me, obj);
     else result = look_item(me, obj);
   } else result = look_room_item(me, arg);

   return result;
}

int look_room(object me, object env)
{
   int i;
   object *inv;
   mapping exits;
   string str, *dirs;

   if( !env ) {
     write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
     return 1;
   }
   str = sprintf( "%s - %s\n    %s%s",
     env->query("short")?env->query("short"): "",
     wizardp(me)? file_name(env): "",
     env->query("long")? env->query("long"): "\n",
     env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

   if( mapp(exits = env->query("exits")) ) {
     dirs = keys(exits);
     for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
          dirs[i] = 0;
     dirs -= ({ 0 });
     if( sizeof(dirs)==0 )
        str += "    ����û���κ����Եĳ�·��\n";
     else if( sizeof(dirs)==1 )
        str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
     else
        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
          implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
   }
//   str += env->door_description();

   inv = all_inventory(env);
   for(i=0; i<sizeof(inv); i++) {
     if( inv[i]==me ) continue;
     if( !me->visible(inv[i]) ) continue;
     str += "  " + inv[i]->short() + ride_suffix(inv[i])+ " " +
            base_name(inv[i])+"\n";
   }

   write(str);
   return 1;
}

int look_item(object me, object obj)
{
   mixed *inv;

//   write(obj->long());
   me->start_more(obj->long());
   inv = all_inventory(obj);
   if( sizeof(inv) ) {
     inv = map_array(inv, "inventory_look", this_object() );
     message("vision", sprintf("�����У�\n  %s\n",
        implode(inv, "\n  ") ), me);
   }
   return 1;
}
string per_status_msg(int age, int per, string gender)
{
   // added by snowcat 
   if (age < 14) {
     if ( per>=25 )
        return ( per_msg_kid1[random(sizeof(per_msg_kid1))]);
     else if ( per>=20 )
        return ( per_msg_kid2[random(sizeof(per_msg_kid2))]);
     else if ( per>=15 )
        return ( per_msg_kid3[random(sizeof(per_msg_kid3))]);
     else    return ( per_msg_kid4[random(sizeof(per_msg_kid4))]);
     }
     
   if ( gender == "����" ) {
     if ( per>=25 )
        return ( per_msg_male1[random(sizeof(per_msg_male1))]);
     else if ( per>=20 )
        return ( per_msg_male2[random(sizeof(per_msg_male2))]);
     else if ( per>=15 )
        return ( per_msg_male3[random(sizeof(per_msg_male3))]);
     else    return ( per_msg_male4[random(sizeof(per_msg_male4))]);
     }
     
   if ( gender == "Ů��" ) {
     if ( per>=25 )
                           return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                   else if ( per>=20 )
                           return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                   else if ( per>=15 )
                           return ( per_msg_female3[random(sizeof(per_msg_female3))]);
         else   return ( per_msg_female4[random(sizeof(per_msg_female4))]);
                }
   else return "";
//   else return "����������ûʲô���\n";
}

int look_living(object me, object obj)
{
   string str, limb_status, pro;
   mixed *inv;
   mapping my_fam, fam;
// added for bian by mon.
        mapping ofamily;
   string ogender,orace;
   int oage;
 
   if(obj->query_temp("d_mana")>0) {
     ofamily=obj->query_temp("family");
     ogender=obj->query_temp("gender");
     orace=obj->query_temp("race");
     oage=obj->query_temp("age");
        } else {
     ofamily=obj->query("family");
     ogender=obj->query("gender");
     orace=obj->query("race");
     oage=obj->query("age");
//fake_age is set as the age when player gets dao-xing:�����ֻء�
//so later on, he/she always looks like the age of that time:)
//but need a "look" to activate all the relatived settings...weiqi
//only when one is not in the status of "bian", check his/her
//fake_age. mon 9/4/97
     if(obj->query("always_young") ) { 
        if(oage>obj->query("fake_age")) {
        //if "age" is less than fake_age, reset fake_age.
        //mon 9/4/97
     oage=obj->query("fake_age");
             } else {
               obj->set("fake_age", oage);
        }
     }
     else{
     if(obj->query("combat_exp") > 729000){
        obj->set("always_young", 1);
        obj->set("fake_age", oage);
     }     
     }
//done with fake_age.
        }


   if( me!=obj )
     message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);

   str = obj->long();
   str = replace_string(str, "��\n", ride_suffix(obj)+"��\n");

   str = replace_string(str, "$n", me->name());
   str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
   str = replace_string(str, "$R", RANK_D->query_respect(me));
   str = replace_string(str, "$r", RANK_D->query_rude(me));


   pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {
   
   if( orace=="����"
   &&   intp(oage) )
     if(oage<10) {
        str += sprintf("%s��������Ȼ������ʮ�ꡣ\n", pro);
     }
     else{
        str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(oage / 10 * 10));
     }

   //check about wife and husband
   if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
     if( (string)me->query("gender")=="Ů��" ){
     str += sprintf("%s������ɷ�\n", pro);
     }
     else{
        str += sprintf("%s��������ӡ�\n", pro);
     }
   }
   // If we both has family, check if we have any relations.
   if( obj!=me
   &&   mapp(fam = ofamily)
   &&   mapp(my_fam = me->query("family")) 
   &&   fam["family_name"] == my_fam["family_name"] ) {
   
     if( fam["generation"]==my_fam["generation"] ) {
        if( ogender == "����" )
          str += sprintf( pro + "�����%s%s��\n",
             my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
             my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
        else
          str += sprintf( pro + "�����%s%s��\n",
             my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
             my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
     } else if( fam["generation"] < my_fam["generation"] ) {
        if( member_array(my_fam["master_id"],
            obj->parse_command_id_list())>-1  )
          str += pro + "�����ʦ����\n";
        else if( my_fam["generation"] - fam["generation"] > 1 )
          str += pro + "�����ͬ�ų�����\n";
        else if( fam["enter_time"] < my_fam["enter_time"] )
          str += pro + "�����ʦ����\n";
        else
          str += pro + "�����ʦ�塣\n";
     } else {
        if( fam["generation"] - my_fam["generation"] > 1 )
          str += pro + "�����ͬ������\n";
        else if( fam["master_id"] == me->query("id") )
          str += pro + "����ĵ��ӡ�\n";
        else
          str += pro + "�����ʦֶ��\n";
     }
   }

/*   if( obj->query("max_kee") )
     str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";
*/

//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

   if( obj->query("looking") ){
     str += pro + (string)obj->query("looking") + "\n";
   } else {
     string looking= per_status_msg((int)obj->query("age"),
            (int)obj->query_per(), ogender);
              if( strlen(looking)>1 && obj->query("per") < 100 )
                    str += pro + looking;
   }
   inv = all_inventory(obj);
   if( sizeof(inv) ) {
     inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
     inv -= ({ 0 });
     if( sizeof(inv) )
        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ��ţ�\n%s\n",
          pro, implode(inv, "\n") );
   }
        
   }

        me->start_more(str);

   if( obj!=me 
   &&   living(obj)
   &&   random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
     write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
     COMBAT_D->auto_fight(obj, me, "berserk");
     return 1;
   }

//this part is  taken from attack.c
//mon 1/22/98
   if( obj!=me 
   && living(obj)
   && userp(obj)
        && random((int)obj->query("bellicosity")/40) > (int)obj->query("cps") ) 
     COMBAT_D->auto_fight(obj, me, "berserk");


   return 1;
}

string inventory_look(object obj, int flag)
{
   string str;

   str = obj->short();
   if( obj->query("equipped") )
     str = HIC "  ��" NOR + str;
   else if( !flag )
     str = "    " + str;
   else
     return 0;

   return str;
}

int look_room_item(object me, string arg)
{
   object env;
   mapping item, exits;

   if( !objectp(env = environment(me)) )
     return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");

   if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
     if( stringp(item[arg]) )
        write(item[arg]);
     else if( functionp(item[arg]) )
        write((string)(*item[arg])(me));
        
     return 1;
   }
   if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
     if( objectp(env = load_object(exits[arg])) )
        look_room(me, env);
     else {
       return notify_fail("��ʲôҲ��������\n");
     }
     return 1;
   }
   return notify_fail("��Ҫ��ʲô��\n");
}

int help (object me)
{
   write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
   return 1;
}
