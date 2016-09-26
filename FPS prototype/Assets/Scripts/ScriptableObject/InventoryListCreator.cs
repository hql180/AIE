using UnityEngine;
using System.Collections;
using System.Collections.Generic;


[CreateAssetMenu(fileName = "Inventory", menuName = "Inventory/List", order = 2)]
public class InventoryListCreator : ScriptableObject
{
    public List<Item> Inventory;
}
