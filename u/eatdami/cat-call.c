
inherit ITEM;

void create()
{
	set_name("����", ({"cat-call", "shao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����Ƶ�С����,����ԡ�chui��\n");
		set("value", 100);
		set("material", "steel");
	}
	setup();
}

int query_autoload(){return 1;}

int init()
{
 add_action("do_chui","chui");
}
int do_chui(string arg)
{
   object pet,me=this_player();
    
  if(!(me->query("pet/make")))   
	return notify_fail("�㴵�˴�����,ʲô��Ҳû����!\n");
  if((pet=find_living(me->query("pet/id")))&&(pet!=find_player(me->query(
            "pet/id")))){
  if(pet->query("p_host")==me->query("id"))
     {
      tell_room(environment(pet),"ֻ��һ����������,"+pet->query("name")+"�ܿ���.\n",pet);
      pet->move(environment(me));
      tell_room(environment(me),pet->query("name")+"�������˹���.\n",pet);
      pet->set_leader(me);
    return 1;
      }
  else{
       if(!stringp(me->query_temp("pet_in")) )
	{ pet=new("/u/wind/cat", 1);
      me->set_temp("pet",pet);
      me->set_temp("pet_in","1");

     pet->move(environment(me));
     tell_room(environment(me),"����һ��,"+pet->query("name")+"��һ�ߴ��˳���!\n",pet);
return 1;
      }
    return notify_fail("�㴵�˴�����,ʲô����Ҳû����!\n");
     }
   }
else{
      if(!stringp(me->query_temp("pet_in")) )
{
	pet=new("/u/wind/cat",1);
      me->set_temp("pet",pet);
      me->set_temp("pet_in","1");
      pet->move(environment(me));   
      pet->set_leader(me);
      tell_room(environment(me),"ֻ������һ��,"+pet->query("name")+"��һ�ߴ��˳���.\n",pet);
  return 1;
    }
 return notify_fail("�㴵�˴�����,ʲô����Ҳû����\n");
}
}
   
