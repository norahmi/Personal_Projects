using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class pipeSpawnerLogic : MonoBehaviour
{
    public GameObject pipe;
    private float spawnRate = 3;
    private float timer = 0;
    private float hightOffset = 6;

    void Start()
    {
        spawnPipe();
    }


    void Update()
    {
        if(timer < spawnRate) 
        { 
            timer += Time.deltaTime;
        } else {
            spawnPipe();
            timer = 0;
        }
    }

    void spawnPipe()
    {
        float lowest = transform.position.y - hightOffset;
        float highest = transform.position.y + hightOffset;

        Vector3 newPosition = new Vector3( transform.position.x, Random.Range(lowest, highest), 0);

        Instantiate(pipe, newPosition, transform.rotation);
    }

}
